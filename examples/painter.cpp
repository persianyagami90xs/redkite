/**
 * File name: painter.cpp
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2019 Iurie Nistor <http://quamplex.com>
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

#include "RkMain.h"
#include "RkWidget.h"
#include "RkPainter.h"
#include "RkPoint.h"
#include "RkLog.h"
#include "RkEvent.h"

class  PainterExample: public RkWidget {
  public:
        PainterExample(RkWidget *parent = nullptr)
                : RkWidget(parent)
                , textPoint(50, 50)
                , startDraw{false}
        {
                RK_LOG_INFO("called");
        }

        ~PainterExample() = default;

  protected:
        void paintEvent(const std::shared_ptr<RkPaintEvent> &event) final
        {
                RK_UNUSED(event);
                RK_LOG_INFO("called");
                if (startDraw) {
                        RkPainter painter(this);
                        //                        painter.drawText("Hello! ("+ std::to_string(textPoint.x()) + ", " + std::to_string(textPoint.x()) + ")",
                        //               textPoint.x(), textPoint.y());
                        painter.drawCircle(textPoint.x(), textPoint.y(), 20);
                }
        }
        
        void mouseButtonPressEvent(const std::shared_ptr<RkMouseEvent> &event) final
        {
                RK_LOG_INFO("mouse press: p(" << event->x() << ", " <<  event->y() << ")");
                textPoint = RkPoint(event->x(), event->y());
                startDraw = true;
                update();
        }
        
  private:
        RkPoint textPoint;
        bool startDraw;
};

int main(int arc, char **argv)
{
    RkMain app(arc, argv);

    auto widget = new PainterExample;
    widget->setTitle("Painter Example");
    widget->show();

    if (!app.setTopLevelWindow(widget)) {
            RK_LOG_ERROR("can't set top level window");
            exit(1);
    }

    return app.exec();
}