#pragma once

class Engine
{
public:

	void Init(const WindowInfo& info);
	void Render();

	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);

private:

	// 그려질 화면 크기 관련
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	std::shared_ptr<class Device> _device;
	std::shared_ptr<class CommandQueue> _cmdQueue;
	std::shared_ptr<class SwapChain> _swapChain;
	std::shared_ptr<class DescriptorHeap> _desHeap;
};

