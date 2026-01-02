#ifndef GPDDATABASE_EXCLUSIVEDATABASEEXCEPTION_H
#define GPDDATABASE_EXCLUSIVEDATABASEEXCEPTION_H

#include <exception>
#include <string>

namespace gpddatabase {

    class ExclusiveDatabaseException : public std::exception {

    private:

        std::string message;

    public:

        explicit ExclusiveDatabaseException(const std::string& msg) : message(msg) {}

        // Override the what() method from std::exception
        const char* what() const noexcept override {
            return message.c_str();
        }
    };

}

#endif //GPDDATABASE_EXCLUSIVEDATABASEEXCEPTION_H