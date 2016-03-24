bin_PROGRAMS =
check_PROGRAMS =
TESTS =
EXTRA_DIST = Readme.md
CLEANFILES =
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

AM_CPPFLAGS = -include $(top_builddir)/config.h
AM_CFLAGS = ${my_CFLAGS}
AM_LDFLAGS =

LIBRARY_CURRENT=0
LIBRARY_REVISION=0
LIBRARY_AGE=0

include_HEADERS = leftpad.h
lib_LTLIBRARIES = libleftpad.la

libleftpad_la_SOURCES = \
	leftpad.c \
	leftpad.h

libleftpad_la_LDFLAGS = $(AM_LDFLAGS) \
	-version-info $(LIBRARY_CURRENT):$(LIBRARY_REVISION):$(LIBRARY_AGE) \
	-export-symbols-regex "^(left_pad.*)"

pkgconfig_DATA = libleftpad.pc
EXTRA_DIST += libleftpad.pc.in
CLEANFILES += libleftpad.pc

TESTS += leftpad-test
check_PROGRAMS += leftpad-test
leftpad_test_SOURCES = leftpad-test.c
leftpad_test_LDADD = libleftpad.la
