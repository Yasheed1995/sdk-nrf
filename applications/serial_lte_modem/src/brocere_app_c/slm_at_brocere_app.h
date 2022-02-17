/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#ifndef SLM_AT_BROCERE_APP_
#define SLM_AT_BROCERE_APP_

/**@file slm_at_mqtt.h
 *
 * @brief Vendor-specific AT command for MQTT service.
 * @{
 */
/**
 * @brief Initialize MQTT AT command parser.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int slm_at_brocere_init(void);

/**
 * @brief Uninitialize MQTT AT command parser.
 *
 * @retval 0 If the operation was successful.
 *           Otherwise, a (negative) error code is returned.
 */
int slm_at_brocere_uninit(void);

int handle_at_test(enum at_cmd_type cmd_type);

/** @} */

#endif /* SLM_AT_GPS_ */
