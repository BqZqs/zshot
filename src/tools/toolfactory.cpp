// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "toolfactory.h"
#include "tools/accept/accepttool.h"
#include "tools/circle/circletool.h"
#include "tools/marker/markertool.h"
#include "tools/move/movetool.h"
#include "tools/pencil/penciltool.h"
#include "tools/pin/pintool.h"
#include "tools/pixelate/pixelatetool.h"
#include "tools/rectangle/rectangletool.h"
#include "tools/sizedecrease/sizedecreasetool.h"
#include "tools/sizeincrease/sizeincreasetool.h"
#include "tools/undo/undotool.h"

ToolFactory::ToolFactory(QObject* parent)
  : QObject(parent)
{}

CaptureTool* ToolFactory::CreateTool(CaptureTool::Type t, QObject* parent)
{
    switch (t) {
        case CaptureTool::TYPE_PENCIL:
            return new PencilTool(parent);
        case CaptureTool::TYPE_MARKER:
            return new MarkerTool(parent);
        case CaptureTool::TYPE_RECTANGLE:
            return new RectangleTool(parent);
        case CaptureTool::TYPE_CIRCLE:
            return new CircleTool(parent);
        case CaptureTool::TYPE_PIXELATE:
            return new PixelateTool(parent);
        case CaptureTool::TYPE_PIN:
            return new PinTool(parent);
        case CaptureTool::TYPE_MOVESELECTION:
            return new MoveTool(parent);
        case CaptureTool::TYPE_SIZEINCREASE:
            return new SizeIncreaseTool(parent);
        case CaptureTool::TYPE_SIZEDECREASE:
            return new SizeDecreaseTool(parent);
        case CaptureTool::TYPE_UNDO:
            return new UndoTool(parent);
        case CaptureTool::TYPE_ACCEPT:
            return new AcceptTool(parent);
        default:
            return nullptr;
    }
}
