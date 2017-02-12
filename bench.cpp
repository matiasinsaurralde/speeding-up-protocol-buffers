#include <iostream>
#include <fstream>
#include <string>

#include <benchmark/benchmark.h>
#include <benchmark/benchmark_api.h>
#include <benchmark/macros.h>
#include <benchmark/reporter.h>

#include <google/protobuf/arena.h>

#include "bindings/person.pb.h"
#include "bindings/lite_person.pb.h"
#include "bindings/speed_person.pb.h"

google::protobuf::Arena the_arena;
google::protobuf::Arena lite_arena;
google::protobuf::Arena speed_arena;

void BM_perform_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    Person p;

    std::string name("john");
    std::string email("john@test.com");

    p.set_name(name);
    p.set_id(1);
    p.set_email(email);

    std::string output;
    p.SerializeToString(&output);
  };
};

void BM_perform_lite_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    LitePerson p;

    std::string name("john");
    std::string email("john@test.com");

    p.set_name(name);
    p.set_id(1);
    p.set_email(email);

    std::string output;
    p.SerializeToString(&output);
  };
};

void BM_perform_speed_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    SpeedPerson p;

    std::string name("john");
    std::string email("john@test.com");

    p.set_name(name);
    p.set_id(1);
    p.set_email(email);

    std::string output;
    p.SerializeToString(&output);
  };
};

void BM_perform_arena_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    Person* p = google::protobuf::Arena::CreateMessage<Person>(&the_arena);

    std::string name("john");
    std::string email("john@test.com");

    p->set_name(name);
    p->set_id(1);
    p->set_email(email); 

    std::string output;
    p->SerializeToString(&output);
  };
};

void BM_perform_arena_lite_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    LitePerson* p = google::protobuf::Arena::CreateMessage<LitePerson>(&lite_arena);

    std::string name("john");
    std::string email("john@test.com");

    p->set_name(name);
    p->set_id(1);
    p->set_email(email); 

    std::string output;
    p->SerializeToString(&output);
  };
};

void BM_perform_arena_speed_serialization(benchmark::State& state) {
  while (state.KeepRunning()) {
    SpeedPerson* p = google::protobuf::Arena::CreateMessage<SpeedPerson>(&speed_arena);

    std::string name("john");
    std::string email("john@test.com");

    p->set_name(name);
    p->set_id(1);
    p->set_email(email); 

    std::string output;
    p->SerializeToString(&output);
  };
};

BENCHMARK(BM_perform_serialization);
BENCHMARK(BM_perform_lite_serialization);
BENCHMARK(BM_perform_speed_serialization);

BENCHMARK(BM_perform_arena_serialization);
BENCHMARK(BM_perform_arena_lite_serialization);
BENCHMARK(BM_perform_arena_speed_serialization);

BENCHMARK_MAIN();
