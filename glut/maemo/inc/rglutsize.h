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

#ifndef _RGLUTSIZE_H_
#define _RGLUTSIZE_H_

/**
 * @class RGlutSize
 * @brief Size class implementation.
 */
template <typename T>
class RGlutSize
{
public:
    RGlutSize()
        : mWidth(0),
          mHeight(0)
    {}

    RGlutSize(const T &width, const T &height)
        : mWidth(width),
          mHeight(height)
    {}

    /*!
     * Sets width of the rectangle.
     */
    void setWidth(const T &width) {
        mWidth = width;
    }

    /*!
     * Retrieves width of the rectangle.
     */
    T width() const {
        return mWidth;
    }

    /*!
     * Sets height of the rectangle.
     */
    void setHeight(const T &height) {
        mHeight = height;
    }

    /*!
     * Retreives height of the rectangle.
     */
    T height() const {
        return mHeight;
    }

    /*!
     * Checks whether the size has height as 0 or width as 0.
     */
    bool isNull() {
        return mWidth == 0 || mHeight = 0;
    }

private:
    T mWidth;
    T mHeight;
};

typedef RGlutSize<int> RGlutSizeI;
typedef RGlutSize<unsigned int> RGlutSizeUI;
typedef RGlutSize<float> RGlutSizeF;
typedef RGlutSize<double> RGlutSizeD;

#endif

