#ifndef _PCB_H_
#define _PCB_H_

#include <stdarg.h>
#include "sys/defs.h"
#include "sys/vfs.h"
#define KSTACK_SIZE 100

struct PCBMemList{
	struct PCBMemList* next;
	uint64_t	    baseAddress;
	uint64_t	    size;
};

struct PCB {
   uint64_t kstack[KSTACK_SIZE];
   uint64_t pid;
   uint64_t ppid;
   uint64_t rsp;
   uint64_t rip;
   char p_name[25]; 
   struct PCB *parent;
   uint64_t child_cnt;
   enum { RUNNING, SLEEPING, ZOMBIE, READY, IDLE, EXIT, WAIT } state;
   int exit_status;
   uint64_t pml4;
   struct mm_struct *mm;
   struct PCB *next;
   uint64_t wait_on_child_pid;
   uint64_t entry;
   uint8_t isUser;
   uint64_t stop;
   struct d_entry *cwd;
   struct vfs_file *fd_table[256];
   int fd_count;
   struct PCBMemList* usedHeapList;
   struct PCBMemList* freeHeapList;
   uint64_t child_list[100];
};

struct mm_struct {
  struct vm_area_struct *vma_list;
  struct vm_area_struct *vma_stack_list;
};

struct vm_area_struct {
  uint64_t start;
  uint64_t end;
  uint64_t size;
  uint64_t access_flags;
  uint64_t type;
  struct vm_area_struct *next, *prev;
};

struct mm_struct* create_mm_struct();

struct vm_area_struct* create_vm_area_struct(uint64_t start, uint64_t end, uint64_t size, uint64_t access_flags, uint64_t type);

void insert_vma(struct mm_struct *mm, uint64_t start, uint64_t end, uint64_t size, uint64_t access_flags, uint64_t type);

struct PCB *create_new_proc(char *p_name, uint8_t isUser);


struct PCB* get_free_task_struct();

struct PCB* get_next_proc();

void print_task_list();

int check_proc_present();
void set_pid(pid_t curr_pid);
void add_proc_to_front(struct PCB* proc);
//void get_next_task();


#endif
