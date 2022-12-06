
all: ./binaries/dijkstra_dynamic_sll ./binaries/dijkstra_dynamic_dll ./binaries/dijkstra_dynamic_dyn_arr ./binaries/dijkstra

#-DSLL_CL
#-DDLL_CL
#-DDYN_ARR_CL

# EXECUTABLES
./binaries/dijkstra_dynamic_sll: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_sll -pthread -DSLL -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/dijkstra_dynamic_dll: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_dll -pthread -DDLL -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/dijkstra_dynamic_dyn_arr: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_dyn_arr -pthread -DDYN_ARR -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/dijkstra: dijkstra.c
		gcc dijkstra.c -o ./binaries/dijkstra

# CLEANS
clean:
	rm *.o

clean_all:
	rm *.o binaries/dijkstra_dynamic_sll binaries/dijkstra_dynamic_dll binaries/dijkstra_dynamic_dyn_arr binaries/dijkstra
