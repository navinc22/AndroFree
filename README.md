
# **AndroFree**

Console application for removing android bloatware implemented in C++.

<img src="./androfree.png" alt="AndroFree.PNG" width=400px>

## ***Important Points***

* This program uses Android Debug Bridge. To setup ADB, head over to
https://developer.android.com/studio/releases/platform-tools.

* Add ADB to your path or move the program to platform-tools directory.

* To enable USB Debugging on your phone, go to
https://developer.android.com/studio/debug/dev-options.

* Use this tool cautiously, you may break some system features if you remove essential system packages.

* One good way is to google "\<vendor> bloatware packages".

## ***Future Goals***

* Abstract the functions using encapsulation.
* Options to get and set display resolution and density.
* Options to get and set per-app permissions.
* Options for screenshot and screen capture.
* Graphical User Interface using Qt6.
* Seperate vendor packages w.r.t. android packages.