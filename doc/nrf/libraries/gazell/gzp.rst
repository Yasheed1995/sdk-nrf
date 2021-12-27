.. _gzp:

Gazell Pairing
##############

.. contents::
   :local:
   :depth: 2

The Gazell pairing library enables applications to use the Gazell Link Layer to provide a secure wireless link between Gazell nodes.
The library is customized for pairing a device (for example, a mouse, keyboard, or remote control) with a host (typically a USB dongle) using Gazell.


Overview
********
See the :ref:`ug_gzp` user guide for more information, such as the features of this library.

This library is used in the :ref:`gzp_dynamic_pairing_host` and :ref:`gzp_dynamic_pairing_device` samples.


Requirements
************

In addition to the resources required by the :ref:`ug_gzll` (see :ref:`gzll_glue_resources`), the Gazell Pairing library also employs three nRF5 peripherals:

* Random Number Generator, for generating keys and tokens.
* AES Electronic Codebook (ECB), for encryption and decryption.
* Non-Volatile Memory Controller (NVMC), for storing of pairing parameters.

In addition, Gazell Pairing employs the following Gazell Link Layer resources:

* Two pipes: one for pairing and one for encrypted data transmission.
* Gazell Pairing determines the channel set used by Gazell.

Since Gazell Pairing requires exclusive access to pipes 0 and :c:macro:`GZP_DATA_PIPE` (default pipe 1), it must control the internal Gazell Link Layer variables ``base_address_0``, ``base_address_1`` and ``prefix_address_byte`` for pipes :c:macro:`GZP_PAIRING_PIPE` (always pipe 0) and :c:macro:`GZP_DATA_PIPE` (configurable).
The main application can use the pipes 2-7.
The ``base_address_1`` applies to these pipes.
Gazell Pairing must also determine whether the RX pipes 0 and 1 are enabled.
Make sure not to affect the ``rx_enabled`` status of these pipes.

The following Gazell Link Layer API functions should not be accessed:

* :c:func:`nrf_gzll_set_base_address_0()`
* :c:func:`nrf_gzll_set_base_address_1()`
* :c:func:`nrf_gzll_set_address_prefix_byte()` (for pipes 0 and 1)
* :c:func:`nrf_gzll_set_rx_pipes_enabled()` (can be used but the enabled status of pipes 0 and 1 should not be modified)
* :c:func:`nrf_gzll_set_channel_table()`


Configuration
*************

The prerequisite :ref:`ug_gzll` should be enabled as described in the Gazell Link Layer :ref:`ug_gzll_configuration` section.

To enable the Gazell Pairing, set the :kconfig:`CONFIG_GAZELL_PAIRING` Kconfig option.

Select the role by either of the following Kconfig options:

* :kconfig:`CONFIG_GAZELL_PAIRING_DEVICE` - Device.
* :kconfig:`CONFIG_GAZELL_PAIRING_HOST` - Host.

To support persistent storage of pairing data, set the :kconfig:`CONFIG_GAZELL_PAIRING_SETTINGS` Kconfig option.

To support encryption, set the :kconfig:`CONFIG_GAZELL_PAIRING_CRYPT` Kconfig option.



API documentation
*****************

| Header file: :file:`include/gzp.h` and :file:`include/gzp_config.h`
| Source file: :file:`subsys/gazell/`

.. doxygengroup:: gzp
   :project: nrf
   :members:
