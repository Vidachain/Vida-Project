
Debian
====================
This directory contains files used to package vidad/vida-qt
for Debian-based Linux systems. If you compile vidad/vida-qt yourself, there are some useful files here.

## vida: URI support ##


vida-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install vida-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your vida-qt binary to `/usr/bin`
and the `../../share/pixmaps/vida128.png` to `/usr/share/pixmaps`

vida-qt.protocol (KDE)

