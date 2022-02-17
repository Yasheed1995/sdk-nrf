/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <logging/log.h>
#include <zephyr.h>
#include <stdio.h>
#include <net/mqtt.h>
#include <net/socket.h>
#include <random/rand32.h>
#include "slm_util.h"
#include "slm_at_host.h"
#include "slm_native_tls.h"
#include "slm_at_mqtt.h"
#include "slm_at_brocere_app.h"

#include <modem/at_cmd.h>

LOG_MODULE_REGISTER(slm_brocere, CONFIG_SLM_LOG_LEVEL);

static struct slm_mqtt_ctx {
	int family; /* Socket address family */
	bool connected;
	struct mqtt_utf8 client_id;
	struct mqtt_utf8 username;
	struct mqtt_utf8 password;
	sec_tag_t sec_tag;
	union {
		struct sockaddr_in  broker;
		struct sockaddr_in6 broker6;
	};
} ctx;

#define THREAD_STACK_SIZE	KB(2)
#define THREAD_PRIORITY		K_LOWEST_APPLICATION_THREAD_PRIO

extern char rsp_buf[SLM_AT_CMD_RESPONSE_MAX_LEN];
extern struct at_param_list at_param_list;

extern int slm_at_parse(const char *at_cmd);

static struct k_thread brocere_mqtt_thread;
static K_THREAD_STACK_DEFINE(brocere_mqtt_thread_stack, THREAD_STACK_SIZE);

static void mqtt_thread_fn(void *arg1, void *arg2, void *arg3)
{
	int err = 0;
	struct pollfd fds;

	ARG_UNUSED(arg1);
	ARG_UNUSED(arg2);
	ARG_UNUSED(arg3);

	LOG_INF("mqtt thread created!");

	while (true) {
		
	}

	LOG_INF("MQTT thread terminated");
}

static int do_mqtt_send_test(void)
{
	int err = 0;

	err = slm_at_parse("AT#XMQTTCON=1,\"test\",\"f7d3fdedcbd94a9893ca220583baa307\",\"f7d3fdedcbd94a9893ca220583baa307\",\"mqtt-qa.chte.cloud\",1883");
	if (err) {
		return err;
	}
	// int i;
	// uint16_t op;
	// err = at_params_unsigned_short_get(&at_param_list, 1, &op);
	// if (err) {
	// 	return err;
	// }
	// else {
	// 	printk("op: %d\n", op);
	// }
	err = handle_at_mqtt_connect(AT_CMD_TYPE_SET_COMMAND);
	if (err) {
		LOG_ERR("connect error, %d", err);
		return err;
	}

	err = slm_at_parse("AT#XMQTTPUB=\"/haagen/v1/publish/6/rawdatalist\",\"7B22726177646174616C697374223A5B7B226964223A223034373030373639303135222C226D616E7566616374757265724964223A2262726F63657265222C227261776461746154696D65223A22323032322D30322D31352031303A34333A3538222C2264617461223A5B7B2273656E736F72223A2274656D70222C2276616C7565223A5B223235225D7D5D7D5D7D\",0");
	err = handle_at_mqtt_publish(AT_CMD_TYPE_SET_COMMAND);
	if (err) {
		LOG_ERR("publish error, %d", err);
		return err;
	}
}

int slm_at_brocere_init(void)
{
	memset(&ctx, 0, sizeof(ctx));

	// k_thread_create(&mqtt_thread, mqtt_thread_stack,
	// 	K_THREAD_STACK_SIZEOF(mqtt_thread_stack),
	// 	mqtt_thread_fn, NULL, NULL, NULL,
	// 	THREAD_PRIORITY, K_USER, K_NO_WAIT);

	return 0;
}

int slm_at_brocere_uninit(void)
{
	return 0;
}

/**@brief handle AT#XBTEST commands
 *  AT#XBTEST=<op>
 *  AT#XMQTTCON?
 *  AT#XMQTTCON=?
 */
int handle_at_test(enum at_cmd_type cmd_type)
{
	int err = -EINVAL;
	uint16_t op;

	switch (cmd_type) {
	case AT_CMD_TYPE_SET_COMMAND:
		LOG_INF("XBTEST SET cmd!");
		err = at_params_unsigned_short_get(&at_param_list, 1, &op);
		if (err) {
			return err;
		}

		if (op == 1) {
			LOG_INF("op is 1");
			do_mqtt_send_test();
			LOG_INF("create mqtt thread!");

		}
		
		break;

	case AT_CMD_TYPE_READ_COMMAND:
		LOG_INF("TEST READ cmd!");
		break;

	case AT_CMD_TYPE_TEST_COMMAND:
		LOG_INF("hi!");
		sprintf(rsp_buf, "\r\n#XBTEST: ????\r\n");
		rsp_send(rsp_buf, strlen(rsp_buf));
		err = 0;
		break;

	default:
		break;
	}

	return err;
}
