AM_CPPFLAGS = $(CPPCUTTER_CFLAGS)  	-I$(top_srcdir)/src/libjson \
									-I$(top_srcdir)/src/libCyberbitGame \
									-I$(top_srcdir)/src/libAsciiGui \
									-DDEBUG

LDFLAGS = -module -rpath $(libdir) -avoid-version -no-undefined
CPPFLAGS = -I/usr/include
TESTS_ENVIRONMENT = NO_MAKE=yes CUTTER="$(CUTTER)"
echo-cutter:
	@echo $(CUTTER)

TESTS = run-test.sh

noinst_LTLIBRARIES = test_physics.la
LIBS = $(CPPCUTTER_LIBS) ${top_builddir}/src/libCyberbitGame.la

test_physics_la_SOURCES = test-physics.cpp
