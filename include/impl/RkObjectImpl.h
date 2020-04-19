/**
 * File name: RkObjectImpl.h
 * Project: Redkite (A small GUI toolkit)
 *
 * Copyright (C) 2020 Iurie Nistor <http://iuriepage.wordpress.com>
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

#ifndef RK_OBJECT_IMPL_H
#define RK_OBJECT_IMPL_H

#include "RkObject.h"

class RkEventQueue;

class RkObject::RkObjectImpl {
 public:
        explicit RkObjectImpl(RkObject* interface, RkObject* parent);
        virtual ~RkObjectImpl();

        void setEventQueue(RkEventQueue *queue);
        RkEventQueue* getEventQueue() const;
        void addObserver(RkObserver *ob);
        void removeObservers(RkObject *obj);
        const std::vector<RkObserver*>& observers() const;
        void addBoundObject(RkObject *obj);
        void removeBoundObject(RkObject *obj);
        void addChild(RkObject* child);
        void removeChild(RkObject* child);

 private:
        RK_DECALRE_INTERFACE_PTR(RkObject)
        RK_DISABLE_COPY(RkObjectImpl)
        RK_DISABLE_MOVE(RkObjectImpl)

        RkEventQueue *eventQueue;
        RkObject *parentObject;
        std::unordered_set<RkObject*> objectChildren;
        std::vector<RkObserver*> observersList;
        std::vector<RkObject*> boundObjects;
};

#endif // RK_OBJECT_IMPL_H
