#ifndef OSSL_PKEY
#define OSSL_PKEY

#define OSSL_PKEY_BN(keytype, name)                                                                \
  /*                                                                                               \
   *  call-seq:                                                                                    \
   *     key.##name -> aBN                                                                         \
   */                                                                                              \
  static mrb_value ossl_##keytype##_get_##name(mrb_state *mrb, mrb_value self)                     \
  {                                                                                                \
    EVP_PKEY *pkey;                                                                                \
    mrb_value value_pkey;                                                                          \
    BIGNUM *bn;                                                                                    \
                                                                                                   \
    value_pkey = mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "pkey"));                               \
    pkey = DATA_PTR(value_pkey);                                                                   \
    bn = pkey->pkey.keytype->name;                                                                 \
    if (bn == NULL)                                                                                \
      return mrb_nil_value();                                                                      \
    return ossl_bn_new(mrb, bn);                                                                   \
  }

#define DEF_OSSL_PKEY_BN(mrb, class, keytype, name)                                                \
  do {                                                                                             \
    mrb_define_method((mrb), (class), #name, ossl_##keytype##_get_##name, MRB_ARGS_NONE());        \
  } while (0)
#endif /* _OSSL_PKEY */
