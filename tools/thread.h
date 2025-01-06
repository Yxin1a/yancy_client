#pragma once
#ifdef HAVE_BUILD_CONFIG_H
  #include <build-config.h>
#endif

#include <thread>
#include <atomic>
#include <system_error>

namespace yancy
{
    template<class C>
    class Thread
    {
    public:
        Thread(C* method_class_ptr, void(C::*method)())
        {
            _method_class_ptr = method_class_ptr;
            _method = method;
            _stop_request = false;
        }

        Thread(Thread& thread)
        {
            _method_class_ptr = thread._method_class_ptr;
            _method = thread._method;
            std::swap(_thread, thread._thread);
            _stop_request = thread._stop_request.load();
        }

        Thread& operator=(Thread& thread)
        {
            _method_class_ptr = thread._method_class_ptr;
            _method = thread._method;
            std::swap(_thread, thread._thread);
            _stop_request = thread._stop_request.load();
            return *this;
        }

        ~Thread()
        {
        }

        void start()
        {
            _stop_request = false;
            _thread = std::thread(_method, _method_class_ptr);
        }

        /**
         * Set the termination flag and wait for the thread
         * to exit.
         */
        void stop(bool do_wait = true)
        {
            _stop_request = true;

            if (do_wait) {
                wait();
            }
        }

        void wait()
        {
            if (_thread.joinable()) {
                try {
                _thread.join();
                }
                catch (const std::system_error& ex) {
                    // SECSERVER_LOG(Error) << ex.what();
                throw;
                }
            }

            _stop_request = false;
        }

        bool running() const
        {
            return (_thread.get_id() != std::thread::id());
        }

        bool stopRequested() const
        {
            return _stop_request;
        }

    private:
        C* _method_class_ptr;
        void(C::*_method)();
        std::thread _thread;
        std::atomic_bool _stop_request;
    };

} /* namespace yancy */

/* vim: set ts=2 sw=2 et */
