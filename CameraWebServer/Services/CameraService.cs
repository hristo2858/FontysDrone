using Iot.Device.Media;

namespace CameraWebServer.Services;

public class CameraService
{
    VideoConnectionSettings settings;
    VideoDevice device;
    CancellationTokenSource tokenSource = new CancellationTokenSource();

    public event VideoDevice.NewImageBufferReadyEvent NewImageReady
    {
        add { device.NewImageBufferReady += value; }
        remove { device.NewImageBufferReady -= value; }
    }

    public CameraService()
    {
        settings = new VideoConnectionSettings(
            busId: 0,
            captureSize: (640, 480),
            pixelFormat: PixelFormat.JPEG
        );
        device = VideoDevice.Create(settings);
        device.ImageBufferPoolingEnabled = true;
    }

    public void StartCapture()
    {
        if (!device.IsOpen)
        {
            device.StartCaptureContinuous();
        }

        if (!device.IsCapturing)
        {
            new Thread(() =>
                {
                    device.CaptureContinuous(tokenSource.Token);
                }
            ).Start();
        }
    }

    public void StopCapture()
    {
        if (device.IsCapturing)
        {
            tokenSource.Cancel();
            tokenSource = new CancellationTokenSource();
            device.StopCaptureContinuous();
        }
    }
}
