#ifndef BABELTRACE_CTF_WRITER_STREAM_INTERNAL_H
#define BABELTRACE_CTF_WRITER_STREAM_INTERNAL_H

/*
 * BabelTrace - CTF Writer: Stream internal
 *
 * Copyright 2013, 2014 Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Author: Jérémie Galarneau <jeremie.galarneau@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <babeltrace/ctf-ir/stream.h>
#include <babeltrace/object-internal.h>
#include <babeltrace/ctf-writer/clock.h>
#include <babeltrace/ctf-writer/event-fields.h>
#include <babeltrace/ctf-writer/event-types.h>
#include <babeltrace/babeltrace-internal.h>
#include <babeltrace/ctf/types.h>
#include <glib.h>

struct bt_ctf_stream {
	struct bt_object base;
	uint32_t id;
	struct bt_ctf_stream_class *stream_class;
	/* Array of pointers to bt_ctf_event for the current packet */
	GPtrArray *events;
	struct ctf_stream_pos pos;
	unsigned int flushed_packet_count;
	GString *name;
	struct bt_ctf_field *packet_header;
	struct bt_ctf_field *packet_context;
	GHashTable *clock_values; /* Maps clock addresses to (uint64_t *) */
};

BT_HIDDEN
int bt_ctf_stream_set_fd(struct bt_ctf_stream *stream, int fd);

BT_HIDDEN
void bt_ctf_stream_update_clock_value(struct bt_ctf_stream *stream,
		struct bt_ctf_field *value_field);

#endif /* BABELTRACE_CTF_WRITER_STREAM_INTERNAL_H */