
# EXECUTABLES
drr_sll_sll: drr_sll_sll.o
		gcc drr_sll_sll.o -o drr_sll_sll

drr_sll_dll: drr_sll_dll.o
		gcc drr_sll_dll.o -o drr_sll_dll

drr_sll_dyn_arr: drr_sll_dyn_arr.o
		gcc drr_sll_dyn_arr.o -o drr_sll_dyn_arr

drr_dll_sll: drr_dll_sll.o
		gcc drr_dll_sll.o -o drr_dll_sll

drr_dll_dll: drr_dll_dll.o
		gcc drr_dll_dll.o -o drr_dll_dll

drr_dll_dyn_arr: drr_dll_dyn_arr.o
		gcc drr_dll_dyn_arr.o -o drr_dll_dyn_arr

drr_dyn_arr_sll: drr_dyn_arr_sll.o
		gcc drr_dyn_arr_sll.o -o drr_dyn_arr_sll

drr_dyn_arr_dll: drr_dyn_arr_dll.o
		gcc drr_dyn_arr_dll.o -o drr_dyn_arr_dll

drr_dyn_arr_dyn_arr: drr_dyn_arr_dyn_arr.o
		gcc drr_dyn_arr_dyn_arr.o -o drr_dyn_arr_dyn_arr


# OBJECT FILES WITH APPROPRIATE FLAGS
drr_sll_sll.o: drr_sll_sll.c drr_sll_sll.h
		gcc -c drr_sll_sll.c

drr_sll_dll.o: drr.c
		gcc -c drr_sll_dll.c

drr_sll_dyn_arr.o: drr.c
		gcc -c drr_sll_dyn_arr.c

drr_dll_sll.o: drr.c
		gcc -c drr_dll_sll.c

drr_dll_dll.o: drr.c
		gcc -c drr_dll_dll.c

drr_dll_dyn_arr.o: drr.c
		gcc -c drr_dll_dyn_arr.c

drr_dyn_arr_sll.o: drr.c
		gcc -c drr_dyn_arr_sll.c

drr_dyn_arr_dll.o: drr.c
		gcc -c drr_dyn_arr_dll.c

drr_dyn_arr_dyn_arr.o: drr.c
		gcc -c drr_dyn_arr_dyn_arr.c


# CLEANS
clean:
	rm *.o

clean_all:
	rm *.o DRR_SLL_SLL DRR_SLL_DLL DRR_SLL_DYN_ARR DRR_DLL_SLL DRR_DLL_DLL DRR_DLL_DYN_ARR DRR_DYN_ARR_SLL DRR_DYN_ARR_DLL DRR_DYN_ARR_DYN_ARR