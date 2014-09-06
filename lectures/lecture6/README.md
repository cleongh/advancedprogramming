# Lecture 6

- Parallelism
    - Parallelism and concurrency: 
      http://stackoverflow.com/questions/1050222/concurrency-vs-parallelism-what-is-the-difference
- Threads
    - C++ threading (high level)
    - boost::thread vs. std::thread: http://stackoverflow.com/questions/7241993/is-it-smart-to-replace-boostthread-and-boostmutex-with-c11-equivalents
- MPI
    - explanation: http://mpitutorial.com/
    - OpenMPI and other implementations: http://www.open-mpi.org/
    - regardless implementation (multicore, network...)
    - is the only messaging passing library considered a standard
    - http://www.open-mpi.org/ (free, available on GNU/Linux)
- Networking
    - boost::asio
    - why you shouldn't use syncs: http://stackoverflow.com/questions/9200005/unblock-synchronous-read-on-boostasioserial-port
    - code in `bots`
    - many libraries can be used


# Exercises

- Add network communication between the server and clients of the bots
    - client is mandatory
    - use async calls
    - you can send pull requests for the server

