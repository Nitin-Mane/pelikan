#pragma once

#include <protocol/admin/process.h>
#include <protocol/memcache/process.h>

#include <buffer/cc_buf.h>
#include <cc_metric.h>

#include <stdbool.h>

/*          name         type              default description */
#define PROCESS_OPTION(ACTION)                                                        \
    ACTION( allow_flush, OPTION_TYPE_BOOL, false,  "allow flushing on the data port" )

/*          name                        type            description */
#define PROCESS_METRIC(ACTION)                                          \
    ACTION( process_req,       METRIC_COUNTER, "# requests processed"  )\
    ACTION( process_ex,        METRIC_COUNTER, "# processing errors"   )\
    ACTION( get,               METRIC_COUNTER, "# get requests"        )\
    ACTION( get_ex,            METRIC_COUNTER, "# get errors"          )\
    ACTION( get_key,           METRIC_COUNTER, "# keys by get"         )\
    ACTION( get_key_hit,       METRIC_COUNTER, "# key hits by get"     )\
    ACTION( get_key_miss,      METRIC_COUNTER, "# key misses by get"   )\
    ACTION( gets,              METRIC_COUNTER, "# gets requests"       )\
    ACTION( gets_ex,           METRIC_COUNTER, "# gets errors"         )\
    ACTION( gets_key,          METRIC_COUNTER, "# keys by gets"        )\
    ACTION( gets_key_hit,      METRIC_COUNTER, "# key hits by gets"    )\
    ACTION( gets_key_miss,     METRIC_COUNTER, "# key misses by gets"  )\
    ACTION( delete,            METRIC_COUNTER, "# delete requests"     )\
    ACTION( delete_deleted,    METRIC_COUNTER, "# delete successes"    )\
    ACTION( delete_notfound,   METRIC_COUNTER, "# delete not_founds"   )\
    ACTION( set,               METRIC_COUNTER, "# set requests"        )\
    ACTION( set_stored,        METRIC_COUNTER, "# set successes"       )\
    ACTION( set_ex,            METRIC_COUNTER, "# set errors"          )\
    ACTION( add,               METRIC_COUNTER, "# add requests"        )\
    ACTION( add_stored,        METRIC_COUNTER, "# add successes"       )\
    ACTION( add_notstored,     METRIC_COUNTER, "# add failures"        )\
    ACTION( add_ex,            METRIC_COUNTER, "# add errors"          )\
    ACTION( replace,           METRIC_COUNTER, "# replace requests"    )\
    ACTION( replace_stored,    METRIC_COUNTER, "# replace successes"   )\
    ACTION( replace_notstored, METRIC_COUNTER, "# replace failures"    )\
    ACTION( replace_ex,        METRIC_COUNTER, "# replace errors"      )\
    ACTION( cas,               METRIC_COUNTER, "# cas requests"        )\
    ACTION( cas_stored,        METRIC_COUNTER, "# cas successes"       )\
    ACTION( cas_exists,        METRIC_COUNTER, "# cas bad values"      )\
    ACTION( cas_notfound,      METRIC_COUNTER, "# cas not_founds"      )\
    ACTION( cas_ex,            METRIC_COUNTER, "# cas errors"          )\
    ACTION( incr,              METRIC_COUNTER, "# incr requests"       )\
    ACTION( incr_stored,       METRIC_COUNTER, "# incr successes"      )\
    ACTION( incr_notfound,     METRIC_COUNTER, "# incr not_founds"     )\
    ACTION( incr_ex,           METRIC_COUNTER, "# incr errors"         )\
    ACTION( decr,              METRIC_COUNTER, "# decr requests"       )\
    ACTION( decr_stored,       METRIC_COUNTER, "# decr successes"      )\
    ACTION( decr_notfound,     METRIC_COUNTER, "# decr not_founds"     )\
    ACTION( decr_ex,           METRIC_COUNTER, "# decr errors"         )\
    ACTION( stats,             METRIC_COUNTER, "# stats requests"      )\
    ACTION( stats_ex,          METRIC_COUNTER, "# stats errors"        )\
    ACTION( flush,             METRIC_COUNTER, "# flush_all requests"  )\
    ACTION( version,           METRIC_COUNTER, "# version requests"    )

typedef struct {
    PROCESS_METRIC(METRIC_DECLARE)
} process_metrics_st;

#define PROCESS_METRIC_INIT(_metrics) do {                              \
    *(_metrics) = (process_metrics_st) { PROCESS_METRIC(METRIC_INIT) }; \
} while(0)

struct request;
struct response;

void process_setup(bool flush, process_metrics_st *process_metrics);
void process_teardown(void);
