
//LICENSE: https://github.com/ruby/openssl/blob/master/LICENSE.txt
#if !defined(_OSSL_DIGEST_H_)
#define _OSSL_DIGEST_H_

void Init_ossl_digest(mrb_state *mrb);
const EVP_MD *GetDigestPtr(mrb_state *mrb, mrb_value);
#endif /* _OSSL_DIGEST_H_ */
