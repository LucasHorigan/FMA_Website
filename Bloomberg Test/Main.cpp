#include <iostream>

// bb_api_cpp_main.cpp
// Example Bloomberg API C++ Program (c)2014 Richard Holowczak
// Portions (c) Bloomberg, LLC

// Bloomberg API Includes
#include <blpapi_defs.h>
#include <blpapi_correlationid.h>
#include <blpapi_element.h>
#include <blpapi_event.h>
#include <blpapi_exception.h>
#include <blpapi_message.h>
#include <blpapi_session.h> 
#include <blpapi_subscriptionlist.h>
#include <string>
#include <stdlib.h>
#include <string.h>
using  namespace BloombergLP; 
using  namespace blpapi; 


int main(int argc, char* argv[])
{
    int result = 0;
    // Define a security and a field
    const char *security = "IBM US Equity";
    const char *fields = "LAST_PRICE";
    // Define a pointer to our event handler based on our class
    BloombergEventHandler *sessionEventHandler;
    // Set of sessionOptions
    SessionOptions sessionOptions;
    sessionOptions.setServerHost("localhost");
    sessionOptions.setServerPort(8194);
    // Instantiate the new EventHandler object
    sessionEventHandler = new BloombergEventHandler();
    // Create a Session object using the sessionOptions
    // and event handler
    Session session(sessionOptions, sessionEventHandler);
    // Start the Session
    result = session.start();
    // Open up the Service to the market data feed
    result = session.openService("//blp/mktdata");
}