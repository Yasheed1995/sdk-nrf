Changelog
#########

All notable changes to this project are documented in this file.

SUPL lib 0.7.1
**************

* Added soft-float build of the library.
* Fixed cell ID encoding in the sent request, so that the server can determine the location of the
  device and send a reference location back to the device. The MCC table is used as a fall back in
  case no reference location is received from the server.
* Reference location is now only injected if it was requested.
* Fixed usage of an IPv6 address as the device ID.
* Removed the dependency to the modem library (modemlib). This version works with both modem library
  and bsdlib.

SUPL lib 0.7.0
**************

* Updated library so that it will work with the new modem library (modemlib),
  this version will not work with bsdlib. For bsdlib support, version 0.6.1
  must be used.

SUPL lib 0.6.1
**************

* Fixed the altitude uncertainty for the MCC case.

SUPL lib 0.6.0
**************

* Initial release.
