/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <stdio.h>

#include "selector_event.h"


static int log_selector_event(const struct event_header *eh, char *buf,
			      size_t buf_len)
{
	const struct selector_event *event = cast_selector_event(eh);

	EVENT_MANAGER_LOG(eh, "id: %" PRIu8 " position: %" PRIu8,
			event->selector_id,
			event->position);
	return 0;
}

static void profile_selector_event(struct log_event_buf *buf,
				   const struct event_header *eh)
{
	const struct selector_event *event = cast_selector_event(eh);

	profiler_log_encode_uint8(buf, event->selector_id);
	profiler_log_encode_uint8(buf, event->position);
}

EVENT_INFO_DEFINE(selector_event,
		  ENCODE(PROFILER_ARG_U8, PROFILER_ARG_U8),
		  ENCODE("selector_id", "position"),
		  profile_selector_event);

EVENT_TYPE_DEFINE(selector_event,
		  IS_ENABLED(CONFIG_DESKTOP_INIT_LOG_SELECTOR_EVENT),
		  log_selector_event,
		  &selector_event_info);
