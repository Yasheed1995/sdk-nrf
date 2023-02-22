SUPL Client library
###################

This is the SUPL Client library module that integrates SUPL client library to NCS. The
GPS sample located at nrf/samples/nrf9160/gps has support for receiving AGPS
data over the SUPL protocol if enabled and the library is installed correctly.

Downloading
***********
The SUPL client library zip file must be downloaded from https://www.nordicsemi.com/Products/Low-power-cellular-IoT/nRF9160.
Click the Downloads box, and you should find "nRF9160 SiP SUPL client library" at the bottom of the page.

Installing
**********
Unzip the downloaded zip file in nrf/ext/lib/bin/ while keeping the folder structure, final folder structure should be nrf/ext/lib/bin/supl/.
The support is enabled by changing the line CONFIG_SUPL_CLIENT_LIB=n in the prj.conf to CONFIG_SUPL_CLIENT_LIB=y.

To build the sample, run the following command in the sample directory:

`west build -b nrf9160dk_nrf9160ns`

To program the nRF91 development kit:

`west flash`

