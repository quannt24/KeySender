#include "xwrapper.h"
#include <X11/Xlib.h>
#include <stdio.h>

void XWrapper::sendKey(unsigned long keysym)
{
    Display* disp = XOpenDisplay(0);
    XKeyEvent kevent;
    Window focuswin;

    int revert_to;
    XGetInputFocus(disp, &focuswin, &revert_to);
    if (focuswin == 0) {
        printf("No focused window!\n");
        return;
    }

    KeyCode keycode = 0;

    keycode = XKeysymToKeycode(disp, keysym);
    if (keycode == 0) {
        printf("crikey: Can't simulate keysym %ld: no keycode\n", keysym);
        return;
    }

    kevent.display = disp;
    kevent.root = DefaultRootWindow(disp);
    kevent.window = focuswin;
    kevent.subwindow = None;
    kevent.time = CurrentTime;
    kevent.x = 1;
    kevent.y = 1;
    kevent.x_root = 1;
    kevent.y_root = 1;
    kevent.same_screen = 1;
    kevent.type = KeyPress;
    kevent.keycode = keycode;
    kevent.state = ShiftMask;
    printf("Sending an event with keycode = %d, modifier mask 0x%x\n",
           kevent.keycode, kevent.state);

    XSendEvent(disp, focuswin, 1, KeyPressMask, (XEvent *)&kevent);
    /* Wonder if we might ever need the key release --
     * but in some contexts, that actually gets interpreted
     * as another key press! XSendEvent(disp, focuswin, TRUE, KeyReleaseMask, (XEvent *)&kevent);
     */
    XSync(disp, False);
    XCloseDisplay(disp);
}
