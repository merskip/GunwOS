//
//  regset.hpp
//  GunwOS Tests
//
//  Created by Artur Danielewski on 25.07.2022.
//

#ifndef REGSET_HPP
#define REGSET_HPP

#include <cstdint>

#define REG_32(NAME) union {    \
    uint32_t e ## NAME;         \
    uint16_t NAME;              \
};

#define GP_REG_32(NAME) union { \
    REG_32( NAME ## x )         \
    struct {                    \
        uint8_t NAME ## h;      \
        uint8_t NAME ## l;      \
    };                          \
};

struct __attribute__((packed, aligned(4))) i386_regSet {
    GP_REG_32(a);
    GP_REG_32(b);
    GP_REG_32(c);
    GP_REG_32(d);
    REG_32(sp);
    REG_32(bp);
    REG_32(si);
    REG_32(di);
    REG_32(ip);

    union {
        uint32_t eflags;
        struct {
            uint16_t _ersvd : 10;
            uint8_t id      : 1;
            uint8_t vip     : 1;
            uint8_t vif     : 1;
            uint8_t ac      : 1;
            uint8_t vm      : 1;
            uint8_t rf      : 1;
            union {
                uint16_t flags;
                struct {
                    uint8_t _rsvd15 : 1;
                    uint8_t nt      : 1;
                    uint8_t iopl    : 2;
                    uint8_t of      : 1;
                    uint8_t df      : 1;
                    uint8_t iF      : 1;
                    uint8_t tf      : 1;
                    uint8_t sf      : 1;
                    uint8_t zf      : 1;
                    uint8_t _rsvd5  : 1;
                    uint8_t af      : 1;
                    uint8_t _rsvd3  : 1;
                    uint8_t pf      : 1;
                    uint8_t _rsvd1  : 1;
                    uint8_t cf      : 1;
                };
            };
        };
    };

    uint16_t cs;
    uint16_t ss;
    uint16_t ds;
    uint16_t es;
    uint16_t fs;
    uint16_t gs;
};

#endif // REGSET_HPP
