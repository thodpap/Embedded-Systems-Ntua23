
all: ./binaries/dijkstra_dynamic_sll ./binaries/dijkstra_dynamic_dll ./binaries/dijkstra_dynamic_dyn_arr 

# EXECUTABLES
./binaries/dijkstra_dynamic_sll: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_sll -pthread -DSLL_CL -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/dijkstra_dynamic_dll: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_dll -pthread -DDLL_CL -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

./binaries/dijkstra_dynamic_dyn_arr: dijkstra_dynamic.c
		gcc dijkstra_dynamic.c -o ./binaries/dijkstra_dynamic_dyn_arr -pthread -DDYN_ARR_CL -lcdsl -L./../synch_implementations -I./../synch_implementations -no-pie

# CLEANS
clean:
	rm *.o

clean_all:
	rm *.o binaries/dijkstra_dynamic_sll binaries/dijkstra_dynamic_dll binaries/dijkstra_dynamic_dyn_arr