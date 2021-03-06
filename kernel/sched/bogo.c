/*
 * kernel/sched/bogo.c
 *
 * Bogo Scheduling Class (mapped to the SCHED_BOGO policy).
 */

#include "sched.h"

const struct sched_class bogo_sched_class = {
    .next               = &fair_sched_class,
    .enqueue_task       = enqueue_task_rt,
    .dequeue_task       = dequeue_task_rt,
    .yield_task         = yield_task_rt,

    .check_preempt_curr = check_preempt_curr_rt,

    .pick_next_task     = pick_next_task_rt,
    .put_prev_task      = put_prev_task_rt,

#ifdef CONFIG_SMP
    .select_task_rq     = select_task_rq_rt,

    .set_cpus_allowed   = set_cpus_allowed_common,
    .rq_online          = rq_online_rt,
    .rq_offline         = rq_offline_rt,
    .task_woken         = task_woken_rt,
    .switched_from      = switched_from_rt,
#endif

    .set_curr_task      = set_curr_task_rt,
    .task_tick          = task_tick_rt,

    .get_rr_interval    = get_rr_interval_rt,

    .prio_changed       = prio_changed_rt,
    .switched_to        = switched_to_rt,

    .update_curr        = update_curr_rt,
};
