#include "pch.h"
#include "Engine.h"
#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "DescriptorHeap.h"

void Engine::Init(const WindowInfo& info)
{
	_window = info;
	ResizeWindow(_window.width, _window.height);

	_viewport = { 0, 0, static_cast<FLOAT>(info.width), static_cast<FLOAT>(info.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, info.width, info.height);
	
	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_desHeap = make_shared<DescriptorHeap>();

	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain, _desHeap);
	_swapChain->Init(info, _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_desHeap->Init(_device->GetDevice(), _swapChain);
}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport, &_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::Render()
{
	RenderBegin();


	RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_window.width = width;
	_window.height = height;

	RECT rect = { 0, 0, _window.width, _window.height };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_window.hWnd, 0, 100, 100, _window.width, _window.height, 0);
}
