/*
 * Copyright (c) 2011, Ranjith TV
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright notice,
       this list of conditions and the following disclaimer
 *     in the documentation and/or other materials provided with the distribution.
 *   * Neither the name the Ranjith nor the names of its contributors may be used
       to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef GLUTEVENTHANDLER_H_
#define GLUTEVENTHANDLER_H_

#include "rcommon.h"

/**
 * @class RGlutEventHandler
 * @brief Listner for events.
 */
class RGlutEventHandler
{
public:
    virtual ~RGlutEventHandler() {}

    /*!
     * Draw callback
     */
    virtual void draw() = 0;
    /*!
     * Shape callback
     */
    virtual void reshape(int w, int h) = 0;
    /*!
     * Rect change callback
     */
    virtual void rerect(int x, int y, int w, int h) = 0;
    /*!
     * Postion change callback
     */
    virtual void repos(int x, int y) = 0;
    /*!
     * Keyboad event callback
     */
    virtual void keyboard(unsigned char key, unsigned int modifier, int x, int y) = 0;
    /*!
     * Mouse press callback
     */
    virtual void mouse(int button, int modifier, int x, int y, bool pressed = true) = 0;
    /*!
     * Mouse motion callback
     */
    virtual void motion(int button, int modifier, int x, int y) = 0;
};

#endif
