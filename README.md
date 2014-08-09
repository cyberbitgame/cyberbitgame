CyberBit Game
=========

This is an open source 2D Side Scroller PC Game.

Git
=========

To download the very latest source off the GIT server do this:

    $ git clone git@github.com:cyberbitgame/cyberbitgame.git

(you'll get a directory named cyberbitgame created, filled with the source code)

How to build Game
=========

Tools required:

* You must have GNU C Compiler gcc.
* You must have autotools on your machine (automake, autoconf and libtool
  packages). Under Ubuntu they are found in build-essential package.
* You must have SDL1.2 (This also requires SDL-devel, SDL_image, SDL_image-devel,
  SDL_mixer, SDL_mixer-devel, SDL_ttf, and SDL_ttf-devel).
  
```$ sudo apt-get install libsdl1.2-dev libsdl-ttf2.0-dev libsdl-sound1.2-dev libsdl-sge-dev libsdl-pango-dev libsdl-net1.2-dev libsdl-mixer1.2-dev libsdl-image1.2-dev libsdl-gfx1.2-dev```

* You must have cutter framework installed (cutter-test_framework package) in
  order to be able to run tests, but this is not required to build the package.

Instructions to build:

* run autogen.sh file (it will generate configure script). ```$ ./autogen.sh```
* On successful run of ./autogen.sh, you will have configure file.
  Run it. ```$ ./configure```
* Next step, is to run make. ```$ make```

For Developers/Contributors
=========

Read [**docs/hacking.md**](docs/hacking.md)

Contact
=========
If you have problems, questions, ideas or suggestions, please contact us
by posting to a mailing list. Mailing list details can be found here:

[**docs/hacking.md**](docs/hacking.md)

All contributors to the project are listed in the [**docs/hacking.md**](docs/hacking.md) document.

Website
=========

Visit the cyberbitgame web site for the latest news and updates:

[cyberbitgame](http://www.cyberbitgame.com/)

