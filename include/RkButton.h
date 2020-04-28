/**
 * File name: RkButton.h
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2020 Iurie Nistor <http://geontime.com>
 *
 * This file is part of Redkite.
 *
 * Redkite is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef RK_BUTTON_H
#define RK_BUTTON_H

#include "RkWidget.h"
#include "RkImage.h"

class RK_EXPORT RkButton: public RkWidget
{
 public:
        enum class ButtonType: int {
                ButtonUncheckable = 0,
                ButtonCheckable   = 1,
                ButtonPush        = 3
        };

        enum class ButtonImage: int {
                ImageUnpressed      = 0,
                ImageUnpressedHover = 1,
                ImagePressed        = 2,
                ImagePressedHover   = 3
        };

        explicit RkButton(RkWidget *parent);
        virtual ~RkButton() = default;
        void setImage(const RkImage &img, ButtonImage type = ButtonImage::ImageUnpressed);
        void setPressed(bool pressed);
        bool isPressed() const;
        ButtonType type() const;
        void setCheckable(bool b);
        bool isCheckable() const;
        void setType(ButtonType type);
        RK_DECL_ACT(toggled,
                    toggled(bool pressed),
                    RK_ARG_TYPE(bool),
                    RK_ARG_VAL(pressed));

 protected:
        virtual void mouseButtonPressEvent(RkMouseEvent *event) override;
        virtual void mouseButtonReleaseEvent(RkMouseEvent *event) override;
        virtual void hoverEvent(RkHoverEvent *event) override;
        virtual void paintEvent(RkPaintEvent *event) override;

 private:
        RK_DELCATE_IMPL_PTR(RkButton);
        RK_DISABLE_COPY(RkButton);
        RK_DISABLE_MOVE(RkButton);
};

#endif // RK_BUTTON_H
