# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-04-14T19:40:22

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [- Wrong Answer-].


## Test 4: [- Command terminated by signal (11: SIGSEGV)-].

## Test 5: [- Wrong Answer-].


## Test 6: [- Wrong Answer-].


## Test 7: [- Wrong Answer-].


## Test 8: [- Wrong Answer-].


## Test 9: [- Command terminated by signal (11: SIGSEGV)-].

## Test 10: [- Wrong Answer-].


## Test 11: [- Wrong Answer-].


## Test 12: [- Command terminated by signal (11: SIGSEGV)-].

## Test 13: [- Command terminated by signal (11: SIGSEGV)-].

## Test 14: [- Wrong Answer-].


## Test 15: [- Wrong Answer-].


## Test 16: [- Wrong Answer-].


## Test 17: [- Command terminated by signal (11: SIGSEGV)-].

## Test 18: [- Command terminated by signal (11: SIGSEGV)-].

## Test 19: [- Command terminated by signal (11: SIGSEGV)-].

## Test 20: [- Command terminated by signal (11: SIGSEGV)-].

## Test 21: [- Wrong Answer-].


## Test 22: [+ Accepted+].
## Test 23: [- Wrong Answer-].


## Test 24: [- Wrong Answer-].


## Test 25: [- Command terminated by signal (11: SIGSEGV)-].

## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [- Command terminated by signal (11: SIGSEGV)-].

## Test 29: [+ Accepted+].
## Test 30: [- Wrong Answer-].


## Test 31: [- Command terminated by signal (11: SIGSEGV)-].

## Test 32: [- Wrong Answer-].




## Number of passed tests: 5/32


## Valgrind Output:


```
==20990== Memcheck, a memory error detector
==20990== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==20990== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==20990== Command: ./proj.out
==20990== 
==20990== Invalid read of size 4
==20990==    at 0x10A2E0: list_stops (list.c:325)
==20990==    by 0x10A2E0: list_stops (list.c:321)
==20990==    by 0x10A2E0: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4b93058 is 24 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10A2E3: list_stops (list.c:325)
==20990==    by 0x10A2E3: list_stops (list.c:321)
==20990==    by 0x10A2E3: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4b93050 is 16 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10A2F0: list_stops (list.c:325)
==20990==    by 0x10A2F0: list_stops (list.c:321)
==20990==    by 0x10A2F0: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4b93048 is 8 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10A2F5: list_stops (list.c:325)
==20990==    by 0x10A2F5: list_stops (list.c:321)
==20990==    by 0x10A2F5: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4b93040 is 0 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==20990==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10A2FC: list_stops (list.c:325)
==20990==    by 0x10A2FC: list_stops (list.c:321)
==20990==    by 0x10A2FC: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4ba4260 is 0 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==20990==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10A2FC: list_stops (list.c:325)
==20990==    by 0x10A2FC: list_stops (list.c:321)
==20990==    by 0x10A2FC: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4ba4261 is 1 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==20990==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==20990==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==20990==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10A2FC: list_stops (list.c:325)
==20990==    by 0x10A2FC: list_stops (list.c:321)
==20990==    by 0x10A2FC: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4ba4267 is 7 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==20990==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==20990==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==20990==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10A2FC: list_stops (list.c:325)
==20990==    by 0x10A2FC: list_stops (list.c:321)
==20990==    by 0x10A2FC: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4ba4265 is 5 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10A2FD: list_stops (list.c:326)
==20990==    by 0x10A2FD: list_stops (list.c:321)
==20990==    by 0x10A2FD: command_p (list.c:373)
==20990==    by 0x1091AA: main (project2.c:39)
==20990==  Address 0x4b93078 is 56 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 4
==20990==    at 0x10B05D: list_intersections (list.c:724)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4b93058 is 24 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10B065: list_intersections (list.c:725)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4b93060 is 32 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10B069: list_intersections (list.c:725)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4b93068 is 40 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10B07F: list_intersections (list.c:726)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4b93040 is 0 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==20990==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10B08F: list_intersections (list.c:726)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4ba4260 is 0 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 1
==20990==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==20990==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==20990==    by 0x4A28735: printf (printf.c:33)
==20990==    by 0x10B08F: list_intersections (list.c:726)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4ba4261 is 1 bytes inside a block of size 9 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x109787: removes_stop.part.15 (list.c:933)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109F54: create_stop (list.c:273)
==20990==    by 0x10A294: command_p (list.c:390)
==20990==    by 0x1091AA: main (project2.c:39)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10B090: list_intersections (list.c:727)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x4b93060 is 32 bytes inside a block of size 64 free'd
==20990==    at 0x48369AB: free (vg_replace_malloc.c:530)
==20990==    by 0x10B5D5: removes_stop (list.c:914)
==20990==    by 0x10B5D5: command_e (list.c:956)
==20990==    by 0x1091DD: main (project2.c:55)
==20990==  Block was alloc'd at
==20990==    at 0x483577F: malloc (vg_replace_malloc.c:299)
==20990==    by 0x109EDD: new_stop (list.c:252)
==20990==    by 0x109113: main (project2.c:23)
==20990== 
==20990== Invalid read of size 8
==20990==    at 0x10B094: list_intersections (list.c:727)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  Address 0x8 is not stack'd, malloc'd or (recently) free'd
==20990== 
==20990== 
==20990== Process terminating with default action of signal 11 (SIGSEGV)
==20990==  Access not within mapped region at address 0x8
==20990==    at 0x10B094: list_intersections (list.c:727)
==20990==    by 0x1091C7: main (project2.c:47)
==20990==  If you believe this happened as a result of a stack
==20990==  overflow in your program's main thread (unlikely but
==20990==  possible), you can try to increase the size of the
==20990==  main thread stack using the --main-stacksize= flag.
==20990==  The main thread stack size used in this run was 8388608.
==20990== 
==20990== HEAP SUMMARY:
==20990==     in use at exit: 264,666 bytes in 146 blocks
==20990==   total heap usage: 339 allocs, 193 frees, 6,762,699 bytes allocated
==20990== 
==20990== LEAK SUMMARY:
==20990==    definitely lost: 262,876 bytes in 42 blocks
==20990==    indirectly lost: 1,790 bytes in 104 blocks
==20990==      possibly lost: 0 bytes in 0 blocks
==20990==    still reachable: 0 bytes in 0 blocks
==20990==         suppressed: 0 bytes in 0 blocks
==20990== Rerun with --leak-check=full to see details of leaked memory
==20990== 
==20990== For counts of detected and suppressed errors, rerun with: -v
==20990== ERROR SUMMARY: 45 errors from 17 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-04-14 19:50:22 @ Lisbon, Portugal. You need to wait 10 minute(s).

