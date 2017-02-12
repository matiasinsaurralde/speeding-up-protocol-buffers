#!/bin/sh
g++ -c bindings/person.pb.cc bindings/lite_person.pb.cc bindings/speed_person.pb.cc
ar rs person.a *person.pb.o
rm *person.pb.o
g++ bench.cpp person.a -o bench `pkg-config protobuf --cflags --libs` `pkg-config protobuf-lite --cflags --libs` -lbenchmark
rm person.a
