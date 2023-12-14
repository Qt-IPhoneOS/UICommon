#ifndef SCREENQUEUE_H
#define SCREENQUEUE_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>
#include <unordered_map>
#include "ScreenManager.h"

namespace uicommon {

class ScreenQueue : public ScreenManager
{
    struct ScreenNode {
        std::pair<uchar, QString> mScreens;
        ScreenNode* mParent;
        std::vector<ScreenNode*> mChildren;

        ~ScreenNode()
        {
            for (auto child : mChildren)
            {
                delete child;
            }
        }

        ScreenNode(std::pair<uchar, QString> screens)
            : mScreens(screens), mParent(nullptr) {}

        void addChild(ScreenNode* child) {
            child->mParent = this;
            mChildren.push_back(child);
        }
    };

    explicit ScreenQueue();

public:
    static ScreenQueue* instance();
    ~ScreenQueue();

    void insertChildrens(ScreenNode*, std::vector<ScreenNode*>);

    void registerRootScreen(const uchar& screenId, const QString& url);
    void registerChildScreen(const uchar& parentScreenId, const uchar& screenId, const QString& url);

    void showNextScreen(const uchar&);
    void showPreviousScreen();

protected:
    uchar mScreenID;
    QString mScreenStr;
    ScreenNode* mRoot;
    ScreenNode* mCurrentScreenNode;
    std::unordered_map<uchar, ScreenNode*> mScreenNodeList;
};

}

#endif // SCREENQUEUE_H
