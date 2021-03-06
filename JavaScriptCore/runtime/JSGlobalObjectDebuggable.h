/**
 * Appcelerator Titanium License
 * This source code and all modifications done by Appcelerator
 * are licensed under the Apache Public License (version 2) and
 * are Copyright (c) 2009-2014 by Appcelerator, Inc.
 */

/*
 * Copyright (C) 2013 Apple Inc. All rights reserved.
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

#ifndef JSGlobalObjectDebuggable_h
#define JSGlobalObjectDebuggable_h

#if ENABLE(REMOTE_INSPECTOR)

#include "RemoteInspectorDebuggable.h"
#include <wtf/Noncopyable.h>

namespace TI {

class JSGlobalObject;

class JSGlobalObjectDebuggable FINAL : public Inspector::RemoteInspectorDebuggable {
    WTF_MAKE_NONCOPYABLE(JSGlobalObjectDebuggable);
public:
    JSGlobalObjectDebuggable(JSGlobalObject&);
    ~JSGlobalObjectDebuggable() { }

    virtual Inspector::RemoteInspectorDebuggable::DebuggableType type() const OVERRIDE { return Inspector::RemoteInspectorDebuggable::JavaScript; }

    virtual String name() const OVERRIDE;
    virtual bool hasLocalDebugger() const OVERRIDE { return false; }

    virtual void connect(Inspector::InspectorFrontendChannel*) OVERRIDE;
    virtual void disconnect() OVERRIDE;
    virtual void dispatchMessageFromRemoteFrontend(const String& message) OVERRIDE;

private:
    JSGlobalObject& m_globalObject;
};

} // namespace TI

#endif // ENABLE(REMOTE_INSPECTOR)

#endif // !defined(JSGlobalObjectDebuggable_h)
