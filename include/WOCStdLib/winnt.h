//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#ifdef _ARM_

// winnt.h includes some ARM intrinsics that cause *strange*
// compilation failures. Work around by getting rid of the enum lookup
// that had an "ambiguous" definition from a single definition (compiler
// complained it was ambiguous with itself). #define the value to the matching
// enum value instead.
#pragma push_macro("_ARM_BARRIER_ISHST")

#define _ARM_BARRIER_ISHST 0xA
#include_next <winnt.h>

#pragma pop_macro("_ARM_BARRIER_ISHST")

#else // Not _ARM_

#include_next <winnt.h>

#endif