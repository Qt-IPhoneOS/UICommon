#ifndef SCREENQUEUE_H
#define SCREENQUEUE_H

#include <QObject>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include <QQmlEngine>
#include <unordered_map>

class ScreenQueue : public QObject
{
    Q_OBJECT

private:

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

    explicit ScreenQueue(QObject* parent = nullptr);

public:
    static ScreenQueue* instance();
    ~ScreenQueue();

    QQuickView* getViewer();
    void createView();
    void insertChildrens(ScreenNode*, std::vector<ScreenNode*>);

    void registerRootScreen(const uchar& screenId, const QString& url);
    void registerChildScreen(const uchar& parentScreenId, const uchar& screenId, const QString& url);
    void registerProperty(const QString& str, const QVariant&);
    void updateProperty(const QString&, const QVariant&);

    Q_INVOKABLE void showNextScreen(const uchar&);
    Q_INVOKABLE void showPreviousScreen();

protected:
    QQuickView* mView {nullptr};
    QQmlContext* mContext {nullptr};

    uchar mScreenID;
    QString mScreenStr;
    ScreenNode* mRoot;
    ScreenNode* mCurrentScreenNode;
    QVector<QString> mContextProperties;
    std::unordered_map<uchar, ScreenNode*> mScreenNodeList;
};

#endif // SCREENQUEUE_H
