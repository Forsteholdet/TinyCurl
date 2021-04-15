

#ifndef TINY_CLIENT_DECODER_H
#define TINY_CLIENT_DECODER_H

#include "response/response.h"
#include "package/package.h"


class Decoder{

public:

    Response decode(Package _package)
    {

        this->package = _package;

        this->statusCode = findStatusCode();

        this->stringBody = findBody();
        
        this->jsonBody = decodeBodyToJson(stringBody);
        
        return Response(statusCode, stringBody);
    }

    bourne::json getJsonBody(){
        return this->jsonBody;
    }

    TinyString getStringBody(){
        return this->stringBody;
    }

    int getStatusCode(){
        return this->statusCode;
    }

private:
    Package package;

    int statusCode;
    TinyString stringBody;
    bourne::json jsonBody;

    int findStatusCode(){return 0;}

    TinyString findBody(){return "default";}

    bourne::json decodeBodyToJson(TinyString stringBody){ return "{'default', 'body'}";}

};

#endif 