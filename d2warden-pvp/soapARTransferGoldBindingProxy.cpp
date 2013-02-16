/* soapARTransferGoldBindingProxy.cpp
   Generated by gSOAP 2.8.3 from ARGoldSoap.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/
#include "stdafx.h"
#include "stdafx.h"
#include "soapARTransferGoldBindingProxy.h"

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy()
{	ARTransferGoldBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy(const struct soap &_soap) : soap(_soap)
{ }

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy(const char *url)
{	ARTransferGoldBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy(soap_mode iomode)
{	ARTransferGoldBindingProxy_init(iomode, iomode);
}

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy(const char *url, soap_mode iomode)
{	ARTransferGoldBindingProxy_init(iomode, iomode);
	soap_endpoint = url;
}

ARTransferGoldBindingProxy::ARTransferGoldBindingProxy(soap_mode imode, soap_mode omode)
{	ARTransferGoldBindingProxy_init(imode, omode);
}

ARTransferGoldBindingProxy::~ARTransferGoldBindingProxy()
{ }

void ARTransferGoldBindingProxy::ARTransferGoldBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "urn:xmethods-ARQuerySaldo", NULL, NULL},
	{"ns2", "urn:xmethods-ARTransferGold", NULL, NULL},
	{"ns3", "urn:xmethods-ARLiveBroadcast", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void ARTransferGoldBindingProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void ARTransferGoldBindingProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *ARTransferGoldBindingProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *ARTransferGoldBindingProxy::soap_fault()
{	return this->fault;
}

const char *ARTransferGoldBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *ARTransferGoldBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int ARTransferGoldBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

void ARTransferGoldBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void ARTransferGoldBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *ARTransferGoldBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int ARTransferGoldBindingProxy::ARTransferGold(const char *endpoint, const char *soap_action, std::string SenderAcc, std::string ReceiverAcc, int Amount, std::string GameName, std::string SenderIP, std::string ReceiverIP, std::string SenderPassword, std::string GSAuthPassword, std::string &return_)
{	struct soap *soap = this;
	struct ns2__ARTransferGold soap_tmp_ns2__ARTransferGold;
	struct ns2__ARTransferGoldResponse *soap_tmp_ns2__ARTransferGoldResponse;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://realm.angrenost.org/soap_server.php";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_tmp_ns2__ARTransferGold.SenderAcc = SenderAcc;
	soap_tmp_ns2__ARTransferGold.ReceiverAcc = ReceiverAcc;
	soap_tmp_ns2__ARTransferGold.Amount = Amount;
	soap_tmp_ns2__ARTransferGold.GameName = GameName;
	soap_tmp_ns2__ARTransferGold.SenderIP = SenderIP;
	soap_tmp_ns2__ARTransferGold.ReceiverIP = ReceiverIP;
	soap_tmp_ns2__ARTransferGold.SenderPassword = SenderPassword;
	soap_tmp_ns2__ARTransferGold.GSAuthPassword = GSAuthPassword;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns2__ARTransferGold(soap, &soap_tmp_ns2__ARTransferGold);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__ARTransferGold(soap, &soap_tmp_ns2__ARTransferGold, "ns2:ARTransferGold", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__ARTransferGold(soap, &soap_tmp_ns2__ARTransferGold, "ns2:ARTransferGold", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&return_)
		return soap_closesock(soap);
	soap_default_std__string(soap, &return_);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns2__ARTransferGoldResponse = soap_get_ns2__ARTransferGoldResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return_ = soap_tmp_ns2__ARTransferGoldResponse->return_;
	return soap_closesock(soap);
}
/* End of client proxy code */
