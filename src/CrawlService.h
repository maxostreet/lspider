/**
 * Autogenerated by Thrift Compiler (0.9.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef CrawlService_H
#define CrawlService_H

#include <thrift/TDispatchProcessor.h>
#include "lspider_types.h"

namespace lspider {

class CrawlServiceIf {
 public:
  virtual ~CrawlServiceIf() {}
  virtual void request(const IUrl& u) = 0;
};

class CrawlServiceIfFactory {
 public:
  typedef CrawlServiceIf Handler;

  virtual ~CrawlServiceIfFactory() {}

  virtual CrawlServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(CrawlServiceIf* /* handler */) = 0;
};

class CrawlServiceIfSingletonFactory : virtual public CrawlServiceIfFactory {
 public:
  CrawlServiceIfSingletonFactory(const boost::shared_ptr<CrawlServiceIf>& iface) : iface_(iface) {}
  virtual ~CrawlServiceIfSingletonFactory() {}

  virtual CrawlServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(CrawlServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<CrawlServiceIf> iface_;
};

class CrawlServiceNull : virtual public CrawlServiceIf {
 public:
  virtual ~CrawlServiceNull() {}
  void request(const IUrl& /* u */) {
    return;
  }
};

typedef struct _CrawlService_request_args__isset {
  _CrawlService_request_args__isset() : u(false) {}
  bool u;
} _CrawlService_request_args__isset;

class CrawlService_request_args {
 public:

  CrawlService_request_args() {
  }

  virtual ~CrawlService_request_args() throw() {}

  IUrl u;

  _CrawlService_request_args__isset __isset;

  void __set_u(const IUrl& val) {
    u = val;
  }

  bool operator == (const CrawlService_request_args & rhs) const
  {
    if (!(u == rhs.u))
      return false;
    return true;
  }
  bool operator != (const CrawlService_request_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CrawlService_request_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CrawlService_request_pargs {
 public:


  virtual ~CrawlService_request_pargs() throw() {}

  const IUrl* u;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CrawlService_request_result {
 public:

  CrawlService_request_result() {
  }

  virtual ~CrawlService_request_result() throw() {}


  bool operator == (const CrawlService_request_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const CrawlService_request_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const CrawlService_request_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class CrawlService_request_presult {
 public:


  virtual ~CrawlService_request_presult() throw() {}


  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class CrawlServiceClient : virtual public CrawlServiceIf {
 public:
  CrawlServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  CrawlServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void request(const IUrl& u);
  void send_request(const IUrl& u);
  void recv_request();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class CrawlServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<CrawlServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (CrawlServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_request(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  CrawlServiceProcessor(boost::shared_ptr<CrawlServiceIf> iface) :
    iface_(iface) {
    processMap_["request"] = &CrawlServiceProcessor::process_request;
  }

  virtual ~CrawlServiceProcessor() {}
};

class CrawlServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  CrawlServiceProcessorFactory(const ::boost::shared_ptr< CrawlServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< CrawlServiceIfFactory > handlerFactory_;
};

class CrawlServiceMultiface : virtual public CrawlServiceIf {
 public:
  CrawlServiceMultiface(std::vector<boost::shared_ptr<CrawlServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~CrawlServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<CrawlServiceIf> > ifaces_;
  CrawlServiceMultiface() {}
  void add(boost::shared_ptr<CrawlServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void request(const IUrl& u) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->request(u);
    }
    ifaces_[i]->request(u);
  }

};

} // namespace

#endif
