#ifndef CC_GFXGLES3_GLES3_EGL_CONTEXT_H_
#define CC_GFXGLES3_GLES3_EGL_CONTEXT_H_

#if (CC_PLATFORM == CC_PLATFORM_MAC_IOS)
#   ifdef __OBJC__
#       include <khronos/OpenGLES/EAGL.h>
#   endif
#else
#   include <khronos/EGL/egl.h>
#   include <khronos/EGL/eglext.h>
#   include <khronos/EGL/eglplatform.h>
#endif

#ifndef EGL_KHR_create_context
#define EGL_KHR_create_context 1
#define EGL_CONTEXT_MAJOR_VERSION_KHR EGL_CONTEXT_CLIENT_VERSION
#define EGL_CONTEXT_MINOR_VERSION_KHR 0x30FB
#define EGL_CONTEXT_FLAGS_KHR 0x30FC
#define EGL_CONTEXT_OPENGL_PROFILE_MASK_KHR 0x30FD
#define EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_KHR 0x31BD
#define EGL_NO_RESET_NOTIFICATION_KHR 0x31BE
#define EGL_LOSE_CONTEXT_ON_RESET_KHR 0x31BF
#define EGL_CONTEXT_OPENGL_DEBUG_BIT_KHR 0x00000001
#define EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE_BIT_KHR 0x00000002
#define EGL_CONTEXT_OPENGL_ROBUST_ACCESS_BIT_KHR 0x00000004
#define EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT_KHR 0x00000001
#define EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT_KHR 0x00000002
#define EGL_OPENGL_ES3_BIT_KHR 0x00000040
#endif

CC_NAMESPACE_BEGIN

class CC_GLES3_API GLES3EGLContext : public GFXContext {
public:
  GLES3EGLContext(GFXDevice* device);
  ~GLES3EGLContext();
  
public:
  bool Initialize(const GFXContextInfo& info);
  void Destroy();
  void Present();
  bool MakeCurrent();

  bool CheckExtension(const String& extension) const;

  CC_INLINE NativeDisplayType native_display() const { return native_display_; }
  CC_INLINE EGLDisplay egl_display() const { return egl_display_; }
  CC_INLINE EGLConfig egl_config() const { return egl_config_; }
  CC_INLINE EGLSurface egl_surface() const { return egl_surface_; }
  CC_INLINE EGLContext egl_context() const { return egl_context_; }
  CC_INLINE EGLContext egl_shared_ctx() const { return egl_shared_ctx_; }
  CC_INLINE int major_ver() const { return major_ver_; }
  CC_INLINE int minor_ver() const { return minor_ver_; }
  
private:
  bool is_primary_ctx_;
  NativeDisplayType native_display_;
  EGLDisplay egl_display_;
  EGLConfig egl_config_;
  EGLSurface egl_surface_;
  EGLContext egl_context_;
  EGLContext egl_shared_ctx_;
  int major_ver_;
  int minor_ver_;
  StringArray extensions_;
  bool is_initialized;
};

CC_NAMESPACE_END

#endif // CC_GFXGLES3_GLES3_EGL_CONTEXT_H_
