#include "ScreenQueue.h"
#include <QDebug>
#include <Log.h>

ScreenQueue::ScreenQueue(QObject *parent) : QObject(parent), mCurrentScreenNode(nullptr)
{
    mView = new QQuickView();
    mContext = mView->rootContext();

    this->registerProperty("ScreenSource", "");
    this->registerProperty("ScreenWidth", 600);
    this->registerProperty("ScreenHeight", 900);
}

ScreenQueue::~ScreenQueue()
{
    delete mRoot;
}

QQuickView *ScreenQueue::getViewer()
{
    return mView;
}

void ScreenQueue::createView()
{
    mView->setSource(QUrl("qrc:/Setting/Screen/main.qml"));
    mView->show();
}

ScreenQueue* ScreenQueue::instance()
{
    static ScreenQueue ins;
    return &ins;
}

void ScreenQueue::insertChildrens(ScreenNode* parent, std::vector<ScreenNode*> childs)
{
    if (parent == nullptr)
        return;

    for (auto& child : childs)
        parent->addChild(child);
}

void ScreenQueue::registerRootScreen(const uchar& screenId, const QString& url)
{
    if (mRoot == nullptr)
        mRoot = new ScreenNode(std::make_pair(screenId, url));

    mCurrentScreenNode = mRoot;
    mScreenNodeList[screenId] = mRoot;
    this->updateProperty("ScreenSource", url);
}

void ScreenQueue::registerChildScreen(const uchar &parentScreenId, const uchar &screenId, const QString &url)
{
    auto it = mScreenNodeList.find(parentScreenId);

    if (it == mScreenNodeList.end())
        return;

    ScreenNode* parent = it->second;
    ScreenNode* node = new ScreenNode(std::make_pair(screenId, url));
    parent->addChild(node);
    mScreenNodeList[screenId] = node;
}

void ScreenQueue::registerProperty(const QString &str, const QVariant &val)
{
    if (mContextProperties.contains(str))
        return;

    mContextProperties.append(str);
    mContext->setContextProperty(str, val);
}

void ScreenQueue::updateProperty(const QString &str, const QVariant &val)
{
    if (!mContextProperties.contains(str))
        return;

    mContext->setContextProperty(str, val);
}

void ScreenQueue::showNextScreen(const uchar& screen)
{
    for (auto& child : mCurrentScreenNode->mChildren)
    {
        auto screenNode = child->mScreens;
        if (screenNode.first == screen)
        {
            mCurrentScreenNode = child;
            mScreenID = screenNode.first;
            mScreenStr = screenNode.second;
            this->updateProperty("ScreenSource", mScreenStr);
        }
    }
}

void ScreenQueue::showPreviousScreen()
{
    if (mCurrentScreenNode->mParent == nullptr)
        return;

    mCurrentScreenNode = mCurrentScreenNode->mParent;
    mScreenID = mCurrentScreenNode->mScreens.first;
    mScreenStr = mCurrentScreenNode->mScreens.second;

    this->updateProperty("ScreenSource", mScreenStr);
}
