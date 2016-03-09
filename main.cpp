#include <QCoreApplication>

#include "XPLMPlugin.h"
#include "XPLMProcessing.h"

QCoreApplication *app = 0;

PLUGIN_API float MyFlightLoopCallback(float inElapsedSinceLastCall, float inElapsedTimeSinceLastFlightLoop, int inCounter, void *inRefcon)
{
    if (app)
    {
        app->processEvents();
        return -1;
    }
    return 1;
}

PLUGIN_API int XPluginStart(char *outName, char *outSig, char *outDesc)
{
    qstrcpy(outName, "Test");
    qstrcpy(outSig, "ch.beh.qttest");
    qstrcpy(outDesc, "Tests Qt eventloop");

    qint32 argc = 0;
    char *argv;

    app = new QCoreApplication(argc, &argv);

    XPLMRegisterFlightLoopCallback(MyFlightLoopCallback, -1, NULL);
    app->processEvents();
    return 1;
}

PLUGIN_API void XPluginStop(void)
{
}

PLUGIN_API void XPluginDisable(void)
{
}

PLUGIN_API int XPluginEnable(void)
{
    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, long inMessage, void *inParam)
{
}
