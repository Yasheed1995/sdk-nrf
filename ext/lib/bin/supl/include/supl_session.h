/*
 * Copyright (c) 2019 - 2021, Nordic Semiconductor ASA
 * All rights reserved.
 *
 * 1. By downloading this software, you acknowledge that all right, title and
 *    interest in and to the software and the proprietary information and all
 *    intellectual property rights with respect thereto are and at all times
 *    shall remain with Nordic Semiconductor ASA, its contributors and third
 *    party licensors. No right, title or interest in or to the software, the
 *    proprietary information and all intellectual property rights with respect
 *    thereto are granted under this License, and you acknowledge that Nordic
 *    Semiconductor ASA’s, its contributors’ and third party licensors’
 *    software, and proprietary information shall remain the property of and
 *    proprietary to Nordic Semiconductor ASA, its contributors and third party
 *    licensors respectively.
 *
 * 2. Redistributions in binary form is allowed but only as embedded into Nordic
 *    Semiconductor ASA nRF91-series of integrated circuit in a product or a
 *    software update for such product. You may not modify, re-link or rebuild
 *    the software or the proprietary information.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    Contributors or third party licensors may be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * 4. This software must only be used with Nordic Semiconductor ASA’s nRF91
 *    integrated circuit.
 *
 * 5. Any software provided under this license must not be reverse engineered,
 *    decompiled, modified and/or disassembled.
 *
 * 6. You are only allowed to use the software and proprietary information to
 *    develop your own IoT end-user products. You are not allowed to
 *    redistribute any of the software or proprietary information, except to the
 *    extent the software or any proprietary information is included in your
 *    end-user IoT product.  You shall ensure that your licensees and customers
 *    of your end-user product may not be able to use or link with your product
 *    or any components of your product for the purposed of further development
 *    of your product (including, without limitation, the development of any
 *    products, software, code, technology, firmware or hardware).
 *
 * 7. If you are a U.S. Government unit or agency subject to the DFARs (the
 *    “DOD”), the software is classified as “Commercial Computer Programs” and
 *    the documentation included in or with the software are classified as
 *    “Commercial Programs Documentation” and, pursuant to the DFARs Section
 *    227.7202, the U.S. Government is acquiring a license to the software and
 *    the documentation in accordance with the terms of this Agreement. If any
 *    of the software are being provided to any unit or agency of the U.S.
 *    Government other than the DOD or if you are a U.S. Government Unit or
 *    agency other than DOD, the software is classified as “Commercial Computer
 *    Programs” and any documentation included in or with the software is
 *    classified as “Commercial Items” and pursuant to FAR Section 12.212, the
 *    U.S. Government is acquiring a license to the software and the
 *    documentation in accordance with the terms of this Agreement.
 *
 * 8. You hereby warrant that the software will only be provided, used, exported
 *    and re-exported in compliance with the laws of the United States,
 *    including without limitation all Export Administration Regulations of the
 *    United States Department of Commerce, and that you bear responsibility for
 *    any violation of such laws and regulations. You certify that you are not
 *    and will not allow access to the software or the proprietary information
 *    to any entity or individual in the (i) List of Specially Designated
 *    Nationals or Consolidated Sanctions List administered by the US Office of
 *    Foreign Assets Control, (ii) any entity or individual located in or part
 *    of any government of any country covered by a United States general trade
 *    embargo, (III) any entity owned 50% or more either individually or in the
 *    aggregate by any of the foregoing individuals or entities and (iv) any
 *    entity or individual in the Denied Persons List, Entity List or Unverified
 *    List administered by the US Bureau of Industry and Security or in a
 *    successor to any of these lists or any similar additional list. If you
 *    become any of the foregoing, you shall (i) immediately inform Nordic
 *    Semiconductor ASA of such status and (ii) your rights to use the software
 *    and the proprietary information shall automatically terminate.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" BY NORDIC SEMICONDUCTOR ASA, ITS
 * CONTRIBUTORS AND THIRD PARTY LICENSORS AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL NORDIC SEMICONDUCTOR ASA, CONTRIBUTORS OR THIRD PARTY LICENSORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE. IF THIS WAIVER OF LIABILTIY FOR ANY REASON IS
 * DISCARDED BY ANY JURISDICTION, NORDIC SEMICONDUCTOR ASA, ITS CONTRIBUTORS AND
 * THIRD PARTY LICENSORS’ LIABILITY SHALL IN NO CIRCUMSTANCE EXCEED AN AGGREGATE
 * OF 50 USD FOR ALL CLAIMS.
 */

#ifndef SUPL_SUPL_SESSION_H_
#define SUPL_SUPL_SESSION_H_

#include <stdbool.h>

#include <nrf_socket.h>

#define LIBSUPL_SEC_BUF_SIZE                (4096)
#define LIBSUPL_PRI_BUF_SIZE                (LIBSUPL_SEC_BUF_SIZE * 3)

#define LIBSUPL_LOG_LEVEL_NONE              (0)
#define LIBSUPL_LOG_LEVEL_ERR               (1)
#define LIBSUPL_LOG_LEVEL_WRN               (2)
#define LIBSUPL_LOG_LEVEL_INF               (3)
#define LIBSUPL_LOG_LEVEL_DBG               (4)

/* SUPL session result codes */
#define LIBSUPL_PARAM_ERR                   (-17)
#define LIBSUPL_ABORT                       (-16)
#define LIBSUPL_DECODER_ERR                 (-15)
#define LIBSUPL_UNSPECIFIED_ERR             (-14)
#define LIBSUPL_TIMEOUT                     (-13)
#define LIBSUPL_INJECTION_SOCKET_ERR        (-12)
#define LIBSUPL_INJECTION_INVALID_DATA      (-11)
#define LIBSUPL_INJECTION_NO_DATA           (-10)
#define LIBSUPL_SESSION_INVALID_ERR         (-9)
#define LIBSUPL_SESSION_MISSING_ERR         (-8)
#define LIBSUPL_SESSION_SLP_MISMATCH_ERR    (-7)
#define LIBSUPL_SESSION_SET_MISMATCH_ERR    (-6)
#define LIBSUPL_SESSION_EXIST_ERR           (-5)
#define LIBSUPL_INVALID_MSG_ERR             (-4)
#define LIBSUPL_SOCKET_ERR                  (-3)
#define LIBSUPL_LPP_DECODE_ERR              (-2)
#define LIBSUPL_ULP_DECODE_ERR              (-1)
#define LIBSUPL_SUCCESS                     (0)

/* Device ID
 * Formats how device_id array SHALL be filled for different choices:
 *
 * IMSI
 * Example 244121303566399
 * devide_id[0] = 0x24;
 * devide_id[1] = 0x41;
 * devide_id[2] = 0x21;
 * devide_id[3] = 0x30;
 * devide_id[4] = 0x35;
 * devide_id[5] = 0x66;
 * devide_id[6] = 0x39;
 * devide_id[7] = 0x90;
 *
 * IPV4
 * Example IP 123.45.67.89
 * devide_id[0] = 123;
 * devide_id[1] = 45;
 * devide_id[2] = 67;
 * devide_id[3] = 89;
 *
 * IPV6
 * Example IP 2001:0db8:85a3:0000:0000:8a2e:0370:7334
 * devide_id[0] = 0x20;
 * devide_id[1] = 0x01;
 * devide_id[2] = 0x0d;
 * devide_id[3] = 0xb8;
 * devide_id[4] = 0x85;
 * devide_id[5] = 0xa3;
 * devide_id[6] = 0x00;
 * devide_id[7] = 0x00;
 * devide_id[8] = 0x00;
 * devide_id[9] = 0x00;
 * devide_id[10] = 0x8a;
 * devide_id[11] = 0x2e;
 * devide_id[12] = 0x03;
 * devide_id[13] = 0x70;
 * devide_id[14] = 0x73;
 * devide_id[15] = 0x34;
 */
#define LIBSUPL_ID_CHOICE_IMSI          (1)
#define LIBSUPL_ID_CHOICE_IPV4          (2)
#define LIBSUPL_ID_CHOICE_IPV6          (3)

#define LIBSUPL_ID_LEN                  (16)


struct agps_data_types {
        uint32_t sv_mask_ephe;
        uint32_t sv_mask_alm;
        uint32_t data_flags;
};

typedef struct lte_params {
	bool status;
	unsigned short mcc[3];
	int mnc_length;
	unsigned short mnc[3];
	unsigned char tac[2];
	unsigned char cid[4];
	unsigned short phys_cid;
} lte_params_t;

typedef struct supl_session_ctx {
	struct agps_data_types agps_types;

	lte_params_t lte_params;

	int device_id_choice;
	unsigned char device_id[LIBSUPL_ID_LEN];

	void *user_data;                          /* OPTIONAL argument for callbacks */
} supl_session_ctx_t;

/**
 * @brief Read callback for incoming SUPL data. MANDATORY.
 *
 * @param[out]  p_buff      Buffer to hold the data to be read.
 * @param[in]   nbytes      Number of bytes to read. Shall not be larger than the size of p_buff.
 * @param[in]   user_data   Optional userdata from supl_session_ctx_t.
 *
 * @return  >0 the number of bytes that were read
 *           0 timeout (1 second)
 *          <0 error
 */
typedef ssize_t (*supl_read_t)(
	void *p_buff,
	size_t nbytes,
	void *user_data);

/**
 * @brief Write callback for outgoing SUPL data. MANDATORY.
 *
 * @param[in] p_buff      Buffer containing the data to send.
 * @param[in] nbytes      Size of data contained on p_buff.
 * @param[in] user_data   Optional userdata from supl_session_ctx_t.
 *
 * @return The number of bytes that were sent on success, or -1 on error.
 */
typedef ssize_t (*supl_write_t)(
	const void *p_buff,
	size_t nbytes,
	void *user_data);

/**
 * @brief Handler callback for decoded SUPL data. MANDATORY.
 *
 * @param[in] agps        Buffer containing the SUPL data.
 * @param[in] agps_size   Size of the SUPL data.
 * @param[in] type        Type of the assistance.
 * @param[in] user_data   Optional userdata from supl_session_ctx_t.
 *
 * @return The number of bytes that were sent on success, or -1 on error.
 */
typedef int (*agps_handler_t)(
	void *agps,
	size_t agps_size,
	uint16_t type,
	void *user_data);

/**
 * @brief Logger callback.
 *        OPTIONAL; if Logger callback is not set, no log messages shall
 *        be output from the libsupl.
 *
 * @param[in] priority    Logging level.
 * @param[in] format      This is the string that contains the text to be
 *                        written. It can optionally contain embedded format
 *                        tags that are replaced by the values specified in
 *                        subsequent additional arguments and formatted as
 *                        requested.
 *
 * @return If successful, the total number of characters written is returned.
 *         On failure, a negative number is returned.
 */
typedef int (*supl_log_t)(int priority, const char *format, ...);

/**
 * @brief Monotonic millisecond counter callback.
 *        OPTIONAL; If millisecond counter callback is not set, libsupl assumes
 *        'read' function shall timeout in 1 second and approximate the
 *        SUPL session related timeouts based on that
 *
 * @return Counter value in milliseconds.
 */
typedef int64_t (*counter_ms_t)(void);

typedef struct supl_api {
	supl_read_t read;
	supl_write_t write;
	agps_handler_t handler;
	supl_log_t logger;
	counter_ms_t counter_ms;
} supl_api_t;

typedef struct supl_buffers {
	char *pri_buf;
	size_t pri_buf_size;
	char *sec_buf;
	size_t sec_buf_size;
} supl_buffers_t;

/**
 * @brief Setup resources persisting over SUPL sessions
 *
 * @param[in]   api   Callback struct.
 * @param[in]   bufs  Buffers struct.
 *
 * @return 0 for success.
 */
int supl_client_init(const supl_api_t *api, const supl_buffers_t *bufs);

/**
 * @brief Execute one SUPL session.
 *
 * @param[in]   p_session_ctx  session context.
 *
 * @return  0 for success
 *         <0 for error
 */
int supl_client_session(supl_session_ctx_t *p_session_ctx);

/**
 * @brief Request SUPL session abort.
 *
 * @param[in]   p_session_ctx  session context.
 *
 * @return  0 for successful request handling.
 */
int supl_client_abort(supl_session_ctx_t *p_session_ctx);

#endif /* SUPL_SUPL_SESSION_H_ */
