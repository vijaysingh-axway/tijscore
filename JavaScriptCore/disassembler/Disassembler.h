/**
 * Appcelerator Titanium License
 * This source code and all modifications done by Appcelerator
 * are licensed under the Apache Public License (version 2) and
 * are Copyright (c) 2009-2014 by Appcelerator, Inc.
 */

/*
 * Copyright (C) 2012, 2013 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#ifndef Disassembler_h
#define Disassembler_h

#include <wtf/Platform.h>
#include <wtf/PrintStream.h>

namespace TI {

class MacroAssemblerCodePtr;

enum InstructionSubsetHint { MacroAssemblerSubset, LLVMSubset };

#if ENABLE(DISASSEMBLER)
bool tryToDisassemble(const MacroAssemblerCodePtr&, size_t, const char* prefix, PrintStream&, InstructionSubsetHint = MacroAssemblerSubset);
#else
inline bool tryToDisassemble(const MacroAssemblerCodePtr&, size_t, const char*, PrintStream&, InstructionSubsetHint = MacroAssemblerSubset)
{
    return false;
}
#endif

// Prints either the disassembly, or a line of text indicating that disassembly failed and
// the range of machine code addresses.
void disassemble(const MacroAssemblerCodePtr&, size_t, const char* prefix, PrintStream& out, InstructionSubsetHint = MacroAssemblerSubset);

} // namespace TI

#endif // Disassembler_h
