FROM ubuntu:24.04 AS builder

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    git \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . .

RUN cmake -S . -B build
RUN cmake --build build
RUN cd build && ctest --output-on-failure

FROM ubuntu:24.04

WORKDIR /app

COPY --from=builder /app/build/ConsolePaint .

CMD ["./ConsolePaint"]