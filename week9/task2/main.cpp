#include <string>

void SendSms(const std::string& number, const std::string& message);
void SendEmail(const std::string& email, const std::string& message);

class INotifier{
public:
    virtual void Notify(const std::string& message) = 0;
};

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const std::string& phone) : _phone(phone) {};
    void  Notify(const std::string& message) override{
        SendSms(_phone, message);
    }
private:
    const std::string& _phone;
};

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const std::string& email) : _email(email) {};
    void  Notify(const std::string& message) override{
        SendEmail(_email, message);
    }
private:
    const std::string& _email;
};