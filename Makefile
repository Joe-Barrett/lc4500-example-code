app: app.cpp commands.cpp packager.cpp tcp_client.cpp
	gcc -Wall $^ -o $@

init: init.cpp commands.cpp packager.cpp tcp_client.cpp
	gcc -Wall $^ -o $@

clean:
	rm *.o lcr_app