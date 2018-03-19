/*
 * created by Le MIn 2017/12/09
 */

#ifndef _MVISOR_SCHED_H_
#define _MVISOR_SCHED_H_

#include <mvisor/vcpu.h>
#include <mvisor/percpu.h>

#define PCPU_AFFINITY_FAIL	(0xffff)

DECLARE_PER_CPU(vcpu_t *, current_vcpu);

typedef struct vmm_pcpu {
	uint32_t pcpu_id;
	int need_resched;
	struct list_head vcpu_list;
} pcpu_t;

void vmm_pcpus_init(void);

uint32_t pcpu_affinity(vcpu_t *vcpu, uint32_t affinity);

void sched_vcpu(void);

#endif