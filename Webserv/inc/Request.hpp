#ifndef REQUEST_HPP
# define REQUEST_HPP

#include "utiles.hpp"

enum HttpMethod
{
	GET,
	POST,
	DELETE,
	PUT,
	HEAD,
	NONE
};

enum ParsingStat
{
	Request_Line,
    Request_Line_Post_Put,
    Request_Line_Method,
    Request_Line_First_Space,
    Request_Line_URI_Path_Slash,
    Request_Line_URI_Path,
    Request_Line_URI_Query,
    Request_Line_URI_Fragment,
    Request_Line_Ver,
    Request_Line_HT,
    Request_Line_HTT,
    Request_Line_HTTP,
    Request_Line_HTTP_Slash,
    Request_Line_Major,
    Request_Line_Dot,
    Request_Line_Minor,
    Request_Line_CR,
    Request_Line_LF,
    Field_Name_Start,
    Fields_End,
    Field_Name,
    Field_Value,
    Field_Value_End,
    Chunked_Length_Begin,
    Chunked_Length,
    Chunked_Ignore,
    Chunked_Length_CR,
    Chunked_Length_LF,
    Chunked_Data,
    Chunked_Data_CR,
    Chunked_Data_LF,
    Chunked_End_CR,
    Chunked_End_LF,
    Message_Body,
    Parsing_Done
};

class Request
{
	private:
		std::string 								r_path;
		std::string 								r_query;
		std::string 								r_fragment;
		std::map<std::string, std::string> 			r_requestHeaders;
		std::vector<u_int8_t>  						r_body;
		std::string									r_boundary;
		HttpMethod									r_method;
		std::map<u_int8_t, std::string>				r_methodStr;
		ParsingStat								    r_state;
		size_t 										r_maxBody;
		size_t										r_bodyLength;
		short										r_errorCode;
		size_t										r_chunkLength;
		std::string									r_storage;
		std::string									r_keyStorage;
		short										r_methodIndex;
		u_int8_t									r_verMajor;
		u_int8_t									r_verMinor;
		std::string									r_serverName;
		std::string									r_bodyStr;

		bool										r_fieldsDoneFlag;
		bool										r_bodyFlag;
		bool										r_bodyDoneFlag;
		bool										r_completeFlag;
		bool										r_chunkedFlag;
		bool										r_multiformFlag;

		void	r_handleHeaders();

	public:
		Request();
        Request(const Request& obj);
        Request& operator=(const Request& obj);
		~Request();

		HttpMethod                                  &getMethod();
        std::string                                 &getPath();
        std::string                                 &getQuery();
        std::string                                 &getFragment();
        std::string                                 getHeader(std::string const &);
		const std::map<std::string, std::string>    &getHeaders() const;
		std::string                                 getMethodStr();
        std::string                                 &getBody();
        std::string                                 getServerName();
        std::string                                 &getBoundary();
        size_t                                getmaxBody();
        bool                                        getMultiformFlag();
        
        void        setMethod(HttpMethod &);
        void        setHeader(std::string &, std::string &);
        void        setMaxBodySize(size_t);
        void        setBody(std::string name);

        void        feed(const char *data, size_t size);
        bool        parsingCompleted();
        void        printMessage();
        void        clear();
        short       errorCode();
        bool        keepAlive();
        void        cutReqBody(int bytes);
		void 		erase_slash_end(std::string &path);
};

#endif
