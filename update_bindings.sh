#!/bin/sh

echo Updating C++ bindings...
cd proto && protoc -I. --cpp_out=../out *.proto

