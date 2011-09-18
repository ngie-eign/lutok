// Copyright 2011 Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#if !defined(LUTOK_STATE_IPP)
#define LUTOK_STATE_IPP

#include <lua.hpp>

#include <lutok/state.hpp>

namespace lutok {


/// Wrapper around lua_newuserdata.
///
/// This allocates an object as big as the size of the provided Type.
///
/// \return The pointer to the allocated userdata object.
///
/// \warning Terminates execution if there is not enough memory.
template< typename Type >
Type*
state::new_userdata(void)
{
    return static_cast< Type* >(new_userdata_voidp(sizeof(Type)));
}


/// Wrapper around lua_touserdata.
///
/// \param index The second parameter to lua_touserdata.
///
/// \return The return value of lua_touserdata.
template< typename Type >
Type*
state::to_userdata(const int index)
{
    return static_cast< Type* >(to_userdata_voidp(index));
}


}  // namespace lutok

#endif  // !defined(LUTOK_STATE_IPP)